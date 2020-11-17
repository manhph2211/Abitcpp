SMART NEBULIZER
=====

# TÓM TẮT NỘI DUNG

- Mục tiêu của dự án là thiết kế và xây dựng một mạch phun sương tạo độ ẩm được người dùng điều khiển thông qua smartphone với giao diện là thông báo nhiệt độ và độ ẩm tại thời điểm hiện tại, đưa ra lời khuyên cho người dùng khi độ ẩm không nằm trong khoảng thích hợp và hai chức năng tắt / bật để người dùng lựa chọn. 
- Trong báo cáo này, thiết kế của mạch để đáp ứng các đặc điểm kĩ thuật được giải thích. Các thông số nhiệt độ, độ ẩm được đo từ cảm biến độ ẩm DHT22 và sử dụng ESP8266 để nhận dữ liệu đó. Các dữ liệu trên được gửi lên Blynk và cho người đọc thấy giao diện như đã miêu tả. Khi người dùng chọn ON/OFF, lệnh được truyền lại cho ESP và điều khiển relay bật / tắt máy phun sương. Sau đó, mạch đã được thử nghiệm trên board mạch trắng, trong hầu hết các trường hợp, các mục tiêu của dự án đã được đáp ứng. Tuy nhiên, dự án cần có một số khuyến nghị để nghiên cứu và phát triển thêm.

# 1: Giới thiệu

## 1.1:Lý do chọn đề tài
+ Nhu cầu thị trường :  Máy phun sương là một thiết bị phổ biến, dễ dùng và có mặt hầu hết trong các văn phòng, trường học, cửa hàng, quán cafe hay trong chính ngôi nhà của chúng ta,… những môi trường sử dụng điều hòa, không khí thường xuyên bị hanh, khô,…
+ Nhận thấy có tiềm năng để phát triển : Các sản phẩm trên thị trường hiện nay hầu hết là phun sương đơn thuần, chưa tích hợp công nghệ bên trong sản phẩm, chưa tương tác với người dùng nên dẫn tới hiện tượng thừa ẩm hoặc quá khô. Dự án của nhóm với mục đích khắc phục những điểm trên.
+ Các thiệt bị, linh kiện dễ mua, giá thành phù hợp với điều kiện của sinh viên.
+ Đề tài đáp ứng được nhu cầu của môn học.
+ Sinh viên dễ dàng hiểu và nắm bắt được các kiến thức cơ bản về điện tử và IoT.

## 1.2:Mục tiêu của dự án
+ Hiểu được 9 bước của quy trình thiết kế.
+ Biết cách sử dụng một số thiết bị điện và phần mềm thiết kế.
+ Xây dựng, làm nên một sản phẩm với mẫu mã đẹp và giá thành tốt nhất có thể, thông minh và đem lai thuận tiện cho người dùng.

# 2: Các yêu cầu kỹ thuật
 
## 2.1: Tóm tắt

### 2.1.1: Tổng quan về sản phẩm
Sản phẩm là một mạch phun sương tạo độ ẩm được người dùng điều khiển thông qua smartphone với giao diện là thông báo nhiệt độ và độ ẩm tại thời điểm hiện tại và hai chức năng tắt / bật để người dùng lựa chọn.
### 2.1.2 Mục đích và phạm vi của bài báo cáo
Bài báo cáo giải quyết các yêu cầu liên quan đến các giai đoạn thiết kế của sản phẩm.

## 2.2 Mô tả sản phẩm

### 2.2.1. Bối cảnh
Sản phẩm độc lập và không liên quan đến sản phẩm nào khác hoặc hệ thống lớn hơn.
### 2.2.2 Giả định
Các trang thiết bị cần có đều có sẵn ở Việt Nam.
### 2.2.3. Ràng buộc
Vi điều khiển không nên tham gia vào sản phẩm.

## 2.3 Yêu cầu

### 2.3.1. Yêu cầu chức năng
+ Phun sương liên tục trong lúc bật.
+ Làm mát trên không gian rộng khoảng 20m2.
+ Luôn hiển thị chính xác nhiệt độ, độ ẩm trên giao diện người dùng.
+ Tự động tắt bật với độ trễ từ lúc người dùng chọn lệnh tắt/bật đến hoạt động tắt/bật của máy phun sương gần như không đáng kể ( nhỏ hơn 0.5s).

## 2.3.2.Yêu cầu phi chức năng
### 2.3.2.1. Hiệu suất
Thời gian trễ < 30ms
### 2.3.2.2. Nền tảng phần cứng
+ Máy phun sương: Đầu vào 24V-2A. Công suất: 16W. Hiệu năng : 500 ml/h
+Bộ adapter cho máy phun :Đầu vào : 100-240V - 50/60Hz. Đầu ra: 24V-2A   
+ Cảm biến độ ẩm DHT22, điện áp hoạt động: 3.3VDC.
+ Relay: đầu ra 3.3V

### 2.3.2.3. Hình dạng, kích thước, mẫu mã
+ Mạch phun sương 5*5*5 cm, đèn led 3 màu.
+ Dây cắm 30 cm
+ Board mạch 5*15*1 cm
+ Adapter 5*10*3 cm
+ Tổng trọng lượng  <500g

### 2.3.2.4. Thời gian phát triển : 8 tuần
### 2.3.2.5. Giá thành:  300.000 đồng
### 2.3.2.5. Bảo hành:  6-12 tháng
### 2.3.2.6. Một số tính năng khác: 
Chạy êm, không gây tiếng ồn, dễ dàng vệ  sinh, dễ thay thế linh kiện, dễ dàng sử dụng.

# 3: Một số thông tin khác

## 3.1: Input cảm biến độ ẩm

Sử dụng Cảm biến độ ẩm DHT22, với thông số kĩ thuật:
- Điện áp hoạt động: 3.3VDC
- Dải độ ẩm hoạt động: 0% - 100% RH, sai số ±2%RH
- Dải nhiệt độ hoạt động: -40°C ~ 80°C, sai số ±0.5°C


## 3.2: ESP8266

- Sử dụng ESP8266 để là thiết bị truyền và nhận dữ liệu trung gian giữa các đầu ra và đầu vào.
- Bằng cách nạp code qua Arduino IDE, cho phép ESP8266 nhận dữ liệu input của DHT22 và thông qua Wifi có thể truyền dữ liệu đó lên Blynk và từ Blynk truyền lại về Relay để điều khiển Máy phun sương.


## 3.3: Blynk
`Tham khảo tại link https://tapit.vn/dong-bo-giua-dieu-khien-bang-tay-va-tu-xa-su-dung-ung-dung-blynk/`
- Cài Board NodeMCU vào Arduino IDE
- Cấu hình app Blynk theo các bước sau: 
  - Có thể tạo tài khoản hoặc dùng tài khoản Facebook.
  - Tạo một project, đây được hiểu giống như là một ứng dụng.
  - Điền tên Project và chọn Board phần cứng (Các bạn có thể chọn NodeMCU hoặc ESP8266).
- Mỗi project, Blynk sẽ gửi 1 mã Auth Token để nhập vào trong code của Board mạch điều khiển NodeMCU
- Có thể lựa chọn nhiều chức năng như nút bấm, hẹn giờ, LCD… để đưa vào project của mình.
- Mỗi đối tượng được chọn sẽ tốn energy (1 đơn vị giới hạn khi bạn dùng server miễn phí).
- Sau khi chọn xong đối tượng, nhấp vào để cấu hình chân, các mức logic… Các cấu hình này sẽ tác động đến board phần cứng. Ví dụ nhất nút thì chân gp16 sẽ chuyển từ trạng thái logic 1 sang logic 0
- Sau khi cài đặt xong trên điện thoại thì các bạn lập trình cho board phần cứng. Thư viện Blynk trên Arduino IDE hỗ trợ rất nhiều ví dụ cho Blynk để các bạn có thể dùng thử, hiểu cách thức hoạt động…

## 3.4: Relay
- Dùng Relay 5V 1 Kênh để điều khiển sự bật tắt của Máy phun sương và nhận sự điều khiển của người dùng qua Blynk và ESP8266.
- Đầu vào 5V DC

## 3.5: Máy phun sương và bộ adapter

- Sử dụng máy tạo sương bằng sóng siêu âm có đèn led. Thông số: 
  - Đầu vào 24V-2A
  - Công suất: 16W
  - Hiệu năng : 500 ml/h
- Bộ adapter cho máy phun:
  - Đầu vào : 100-240V - 50/60Hz
  - Đầu ra:     24V-2A

## 3.6: Nguồn cấp

Do nguồn ra ESP8266 chỉ là 3.3V nhưng nguồn nhận của relay là 5V, nhóm quyết định dùng dây MicroUSB nạp nguồn cho relay thay vì dùng ESP8266, và cũng là nguôn cấp cho ESP8266 ( có 2 cổng ra)
- Nguồn cấp chính là pin dự phòng với  thông số đầu ra 2 cổng như sau:
  - Cổng 1: 5VDC -1A
  - Cổng 2: 5VDC- 2.1A

# 4: Bàn giao, vận hành, sửa chữa

# 4.1: Bàn giao

Sản phẩm sẽ được đóng gói hoàn thiện và được giao cho khách hàng ( nếu có!!!)

# 4.2: Bảo hành

Dựa trên tuổi thọ trung bình của các linh kiện và tần suất làm việc của mạch thì chúng em đưa ra chế độ bảo hành 6 tháng, trong 6 tháng nếu có bất kỳ sự sai lệch, lỗi nào liên quan đến phần cứng, do nhà sản suất thì chúng tôi xin chịu hoàn toàn trách nhiệm sửa chữa và giao lại cho khách hàng trong một kỳ:v Sau 6 tháng thì hiệu lực bảo hành sẽ không còn, khách hàng có thể mua thêm gói bảo hành 6 tháng tiếp.

# 4.3: Bảo dưỡng

Chúng em đưa ra 2 gói bảo dưỡng định kỳ hàng tháng và hàng quý, tùy vào nhu cầu của khách hàng có thể chọn bất kỳ một gói hoặc không chọn!



# 5: Kết luận

Trong đề tài này, chúng em đã nghiên cứu và lắp đặt thành công một máy phun sương siêu âm có ứng dụng IoT đơn giản. Tuy cũng có một số vấn đề trong quá trình hoàn thiện sản phẩm nhưng cuối cùng cũng máy phun sương cũng đã chạy tốt và rất hợp lý. Trong thời gian tới có thể nhóm sẽ nghiên cứu thêm một số hướng mở rộng của sản phẩm cũng như tiếp tục phát triển và hoàn thiện hơn nữa sao cho phù hợp nhất với thị trường.
Để có được sản phẩm này, chúng em đã nhờ tới sự giúp đỡ rất nhiệt tình, ân cần của cô Trương Thu Hương, các anh chị trong lab thầy Tiến và các bạn trong lớp KSTN DTTT K63. Nhóm ba con sâu xin cảm ơn rất nhiều ạ!  

