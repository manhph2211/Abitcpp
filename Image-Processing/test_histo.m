clc;


%dung ham cua MATLAB
%mo anh dau vao
img = imread('3.pgm');
%histogram
img2 = histeq(img);


subplot(2,4,1);   % hinh hien len dang 2*4, 1 chinh la cai dang xet
imshow(img);
title('Original image');


subplot(2,4,2);
imshow(img2);
title('Equalizing by Matlab');

subplot(2,4,5);
imshow(img);
title('Original image');


[counts,x] = imhist(img);
[counts1,x1] = imhist(img2);
subplot(2,4,3);
stem(x,counts);
title('Before Equalizing');
subplot(2,4,4);
stem(x1,counts1);
title('After Equalizing');
%khong dung ham cua MATLAB

%histogram equalization
fp2 = fopen('KETQUA_ANH_3.txt','r');
C = fscanf(fp2, '%d %d', [512 512]);
fclose(fp2);
D = C.';



equalized_image = uint8(D);
subplot(2,4,6);
imshow(equalized_image);

title('Equalizing by Algorithm');
[counts2,x2] = imhist(img);
subplot(2,4,7);
stem(x2,counts2);

title('Before Equalizing');
[counts3,x3] = imhist(equalized_image);
subplot(2,4,8);
stem(x3,counts3);
title('After Equalizing');
