
# ĐỀ BÀI:

## Yêu cầu chung:

Ứng viên tìm hiểu lý thuyết về tăng cường chất lượng ảnh bằng điều chỉnh mức xám [2] và
bộ lọc làm mịn ảnh Median Filter[1] triển khai 2 thuật toán này này bằng code C hoặc
C++.

## Yêu cầu đầu vào đầu ra của chương trình:

### 1) Ảnh đầu vào là ảnh xám kích thước tối đa 512x512 lưu dưới dạng text.Trong
đó dòng1,2,…512 lưu giá trị độ xám (từ 0 đến 255) các điểm ảnh ởcác cột
1,2,…512 của dòng 1, 2,…512 tương ứng. Các ảnh đầu vào lấy từ bộ dữ liệu ảnh
[3]. File text chứa ảnh có thể lấy ở đường link [4]

### 2) Ảnh đầu ra là ảnh sau khi đã được làm mịn hoặc chỉnh độ xám được lưu dưới dạng text sau với định dạng tương tự như ảnh đầu vào.

### 3) Chương trình cần đọc file ảnh txt đầu vào, tiến hành thuật toán cân bằng histogram và/hoặc làm mịn và ghi ảnh đầu ra

#### 1) Đặt vấn đề

##### a. Nêu khái niệm (chức năng, nhiệm vụ) của chức năng cân bằng xám và bộ lọc làm mịn ảnh.

##### b. Nêu một số kịch bản sử dụng tính năng cân bằng mức xám và bộ lọc làm mịn ảnh trong thực tế cuộc sống

#### 2) Lý thuyết cơ bản

##### a. Trình bày các khái niệm lý thuyết về biểu diễn ảnh xám bằng các điểm ảnh

##### b. Vẽ lưu đồ thuật toán và trình bày thuật toán cân bằng histogram để điều chỉnh độ sáng tối

##### c. Vẽ lưu đồ thuật toán và trình bày thuật toán làm mịn ảnh dùng Median Filter

#### 3) Trình bày cách thiết kế cấu trúc dữ liệu lưu trữ ảnh cũng nhưcác thông số liên quan đến 2 thuật toán nói trên

#### 4) Trình bày mã nguồn triển khai 02 thuật toán – các biến, các hàm và các vòng lặp

#### 5) Trình bày phương án chạy thử nghiệm

##### a. Mô tả các ảnh đầu vào, kích thước, đặc điểm về độ sáng, mức độ nhiễu

##### b. Cách thức chạy chương trình để thức hiện thuật toán

##### c. Phương án đánh giá ảnh đầu ra 

##### d. Kết quả thử nghiệm trên tập các ảnh đầu vào.

# Tài liệu tham khảo:
[1] Median filter, Wikipedia, Web page: https://en.wikipedia.org/wiki/Median_filter
Nhóm nghiên cứu EDABK/BKI
Đại học Bách Khoa Hà Nội

[2] Histogram equalization, Wikipedia, Web page: https://en.wikipedia.org/wiki/Histogram_equalization

[3] CVG-UGR Image Dataset, Webpage:http://decsai.ugr.es/cvg/dbimagenes/g512.php

[4] https://drive.google.com/drive/folders/1XTDVKmk3WGaXVXbTyml5XA7UEg_qnGRT
