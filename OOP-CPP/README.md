SHAPE MANAGEMENT
=====


# TASK 1

## Chương trình quản lý các đối tượng vector trên màn hình

- Tròn
- Vuông
- Chữ nhật
- Ellipse
- Tam giác

## Mỗi đối tượng có thuộc tính

- Vị trí (tâm của hình)
- Kích thước (tùy thuộc loại hình - cạnh, bán kính, ...)
- Màu, Nét vẽ (độ dầy mỏng)

## Các yêu cầu

- Tất cả class luôn phải có các constructor and destructor phù hợp
- Xây dựng chương trình chính có mảng quản lý các hình (mảng con trỏ đến lớp trừu tượng)
- Chương trình chính cho phép tạo một đối tượng loại bất kỳ
- Chương trình chính cho phép in toàn bộ đối tượng hình bằng 1 vòng lặp (Dùng khái niệm đa hình)
- Vẽ UML Class Diagram để biểu diễn mối quan hệ giữa các class.

https://cppcodetips.wordpress.com/2013/12/23/uml-class-diagram-explained-with-c-samples/


# TASK 2

## Sử dụng các hàm trong STL
http://www.mediafire.com/file/5o1gllos4gjkz3k/STL.pdf/file?fbclid=IwAR0qPQZ-oCY_bgM_2DCIsKm5vZZ_amWvi-wtwYcJOrLu9bNYRjnebVHVZ3E

## Sử dụng các hàm nạp chồng hàm, toán tử cho tiện sử dụng


## Viết hàm đọc file txt thuận tiện hơn cho initialization.

- Viết thêm hàm tính chu vi, diện tích các hình đã xây dựng
- Sắp xếp các hình theo diện tích, chu vi tăng dần hoặc giảm dần. In ra toàn bộ các hình đó. Yêu cầu dùng 2 cách:

1) Dùng sort của thư viện algorithm 
2) Tạo hàm sort có đối số con trỏ hàm trỏ tới các hàm bool phù hợp

- Tìm kiếm 1 hình bất kỳ thông qua vị trí tâm

# TASK 3

- Mở rộng chương trình để thêm cạnh nối tâm của 2 hình đã được lưu(2 hình được nhập vào)
- Khai báo 1 class edge ( có 2 reference đến 2 shapes, có màu, độ dày).
- Xuất hết tất cả các edges có thể với list shape đã có

# TASK 4

- Design pattern factory: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Factory
https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/

- Xây dựng lớp factory để tạo các shape khác nhau.
( Xây dựng hàm trong lớp factory để tạo shape với tham số là kiểu shape )

- Xây dựng đoạn chương trình đọc file text có định dạng như sau:

1) Mỗi dòng chứa các thông số của shape hoặc edge
2) Các thông số được cho trong dấu ngoặc nhọn {}
3) Các thông số cách nhau bởi dấu phẩy (,)
4) Thông số đầu tiên là loại shape n   
5) Tùy thuộc vào thông số đầu tiên về loại shape các thông số sau tương ứng với vị trí, kích thước, mầu và độ dầy cạnh
6) Dòng chứa cạnh nối shape có 2 thông số đầu tiên là index của shape (bắt đầu từ 1)


```
VD về file txt: 
shape{circle,10,10,5.2,red,1} 
shape{rect,15,15,13.1,5.3,blue,2} 
shape{oval,12,12,14.1,7.2,yellow,5} 
shape{tri,20,20,10,14,17,orange,7} 
edge{1,2,green,8} 
edge{3,2,grey,1}   
```


- NOTE

  - Cần xây dựng hàm readShape(virtual) and readEdge cho phù hợp!

  - Làm theo 3 cách:

    - Đọc file sử dụng stringstream
    - Đọc file sử dụng atof hoặc stof
    - Đọc file sử dụng biến tring đọc ký tự đặc biệt và đọc thẳng biến số luôn


- Xây dựng class Graph:

1) Chứa 2 thuộc tính: vector<Shape*> và vector<Edge*>
2) Xây dựng hàm construction và destruction cho Graph
3) Xây dựng các hàm, chức năng trong graph sao cho hàm main() chỉ có dạng như sau:

```
int main()  
{ 
	graph g; 
	do{ 
		g.menu(); 
	}while(1); 
	return 0; 
} 
```


# TASK 5

- Đọc hiểu khái niệm FSM: https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2

- Triển khai FSM cho chương trình Shape: http://www.cplusplus.com/forum/general/91043/

- Yêu cầu:
  - Xác định các biến lưu trạng thái của class Graph
  - Xác định các trạng thái/status của phần mềm Graph i.e. các giá trị của biến trạng thái
  - Xây dựng lại menu cho chương trình Graph sử dụng FSM pattern
  - Xác định các chuyển trạng thái và điều kiện chuyển trạng thái 
