# include <opencv2/opencv.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/videoio.hpp>
#include <Windows.h>

int main(int argc, char * const argv[]){
  // モニターサイズ取得
  HWND desktop = GetDesktopWindow();
  RECT rect;
  GetWindowRect(desktop, &rect);


  // DIBの情報を設定する
  BITMAPINFO bmpInfo;
  bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
  bmpInfo.bmiHeader.biWidth = rect.right;
  bmpInfo.bmiHeader.biHeight = -rect.bottom;
  bmpInfo.bmiHeader.biPlanes = 1;
  bmpInfo.bmiHeader.biBitCount = 24; //cv::Matの画像をアルファチャンネル有りにする場合はは32;
  bmpInfo.bmiHeader.biCompression = BI_RGB;


  LPDWORD lpPixel;
  HDC hDC = GetDC(desktop);
  HBITMAP hBitmap = CreateDIBSection(hDC, &bmpInfo, DIB_RGB_COLORS, (void**)&lpPixel, NULL, 0);
  HDC hMemDC = CreateCompatibleDC(hDC);
  SelectObject(hMemDC, hBitmap);

  cv::Mat monitor_img;
  monitor_img.create(rect.bottom, rect.right, CV_8UC3); //RGBのみ。アルファちゃんねるを加えるにはCV_8UN4
  
  // 画像表示用のWindowを作成（ウィンドウの大きさを640x480に固定する）
  cv::namedWindow("Screenshot", cv::WINDOW_NORMAL);
  cv::resizeWindow("Screenshot", 640, 480);

  while (true){
    //hDCの画像（スクリーンショット）をhMemDCにコピーする
    BitBlt(hMemDC, 0, 0, rect.right, rect.bottom, hDC, 0, 0, SRCCOPY);
    // hMemDCの内容をcv::Matの画像（monitor_img）にコピー
    GetDIBits(hMemDC, hBitmap, 0, rect.bottom, monitor_img.data, (BITMAPINFO *)&bmpInfo, DIB_RGB_COLORS);  //copy from hwindowCompatibleDC to hbwindow

    cv::imshow("Screenshot", monitor_img); // スクリーンショットの表示    
    if (cv::waitKey(1) == 27) break; //Escキーで終了
  }

  //メモリ開放
  ReleaseDC(desktop, hDC);
  DeleteDC(hMemDC);
  DeleteObject(hBitmap);

  return 0;
}