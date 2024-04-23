/******************************************************************
摄像头底层
*******************************************************************/
#include "capture_thread.h"

void CaptureThread::run()
{
    /* 下面的代码请参考正点原子C应用编程V4L2章节，摄像头编程，这里不作解释 */
#ifdef linux
#ifndef __arm__
    return;
#endif
    int video_fd = -1;
    struct v4l2_format fmt;
    struct v4l2_requestbuffers req_bufs;
    static struct v4l2_buffer buf;
    int n_buf;
    struct buffer_info bufs_info[VIDEO_BUFFER_COUNT];
    enum v4l2_buf_type type;

    video_fd = open(VIDEO_DEV, O_RDWR);
    if (0 > video_fd) {
        printf("ERROR: failed to open video device %s\n", VIDEO_DEV);
        return ;
    }

    /* 设置帧格式 */
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 640;
    fmt.fmt.pix.height = 480;
    fmt.fmt.pix.colorspace = V4L2_COLORSPACE_SRGB;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB565;
    if (0 > ioctl(video_fd, VIDIOC_S_FMT, &fmt)) {
        printf("ERROR: failed to VIDIOC_S_FMT\n");
        close(video_fd);
        return ;
    }


    /* 申请帧缓冲 */
    req_bufs.count = VIDEO_BUFFER_COUNT;
    req_bufs.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req_bufs.memory = V4L2_MEMORY_MMAP;
    if (0 > ioctl(video_fd, VIDIOC_REQBUFS, &req_bufs)) {
        printf("ERROR: failed to VIDIOC_REQBUFS\n");
        return ;
    }

    /* 建立内存映射 */
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    for (n_buf = 0; n_buf < VIDEO_BUFFER_COUNT; n_buf++) {/*遍历所有的视频缓冲区*/

        buf.index = n_buf;
        if (0 > ioctl(video_fd, VIDIOC_QUERYBUF, &buf)) {/*查询缓冲区的状态*/
            printf("ERROR: failed to VIDIOC_QUERYBUF\n");
            return ;
        }
        bufs_info[n_buf].length = buf.length;           /*缓冲区长度保存到bufs_info*/
        bufs_info[n_buf].start = mmap(NULL, buf.length,/*将设备的视频缓冲区映射到进程的地址空间*/
                                      PROT_READ | PROT_WRITE, MAP_SHARED,
                                      video_fd, buf.m.offset);
        if (MAP_FAILED == bufs_info[n_buf].start) {
            printf("ERROR: failed to mmap video buffer, size 0x%x\n", buf.length);
            return ;
        }
    }


    /* 入队 */
    for (n_buf = 0; n_buf < VIDEO_BUFFER_COUNT; n_buf++) {

        buf.index = n_buf;
        if (0 > ioctl(video_fd, VIDIOC_QBUF, &buf)) {/*将指定的缓冲区排队到视频设备的缓冲区队列中*/
            printf("ERROR: failed to VIDIOC_QBUF\n");
            return ;
        }
    }

    /* 打开摄像头、摄像头开始采集数据 */
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (0 > ioctl(video_fd, VIDIOC_STREAMON, &type)) {
        printf("ERROR: failed to VIDIOC_STREAMON\n");
        return ;
    }

    while (startFlag) {

        for (n_buf = 0; n_buf < VIDEO_BUFFER_COUNT; n_buf++) {

            buf.index = n_buf;

            if (0 > ioctl(video_fd, VIDIOC_DQBUF, &buf)) {
                printf("ERROR: failed to VIDIOC_DQBUF\n");
                return;
            }

            QImage qImage((unsigned char*)bufs_info[n_buf].start, fmt.fmt.pix.width, fmt.fmt.pix.height, QImage::Format_RGB16);

            /* 是否开启本地显示，开启本地显示可能会导致开启广播卡顿，它们互相制约 */
            if (startLocalDisplay)
                emit imageReady(qImage);

            /* 是否开启广播，开启广播会导致本地显示卡顿，它们互相制约 */
            if (startBroadcast) {
//                /* udp套接字 */
//                QUdpSocket udpSocket;

//                /* QByteArray类型 */
//                QByteArray byte;

//                /* 建立一个用于IO读写的缓冲区 */
//                QBuffer buff(&byte);

//                /* image转为byte的类型，再存入buff */
//                qImage.save(&buff, "JPEG", -1);

//                /* 转换为base64Byte类型 */
//                QByteArray base64Byte = byte.toBase64();

//                /* 由udpSocket以广播的形式传输数据，端口号为8888 */
//                udpSocket.writeDatagram(base64Byte.data(), base64Byte.size(), QHostAddress::Broadcast, 8888);
            }

            if (0 > ioctl(video_fd, VIDIOC_QBUF, &buf)) {
                printf("ERROR: failed to VIDIOC_QBUF\n");
                return;
            }
        }
    }

    msleep(800);//at lease 650

    for (int i = 0; i < VIDEO_BUFFER_COUNT; i++) {/*解除映射缓冲区*/
        munmap(bufs_info[i].start, buf.length);
    }

    close(video_fd);
#endif
}
