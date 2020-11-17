clc;
%Dung ham MATLAB
img = imread('2.pgm');
% lam min anh
img1 = medfilt2(img);
% hien thi tung anh

subplot(2,4,1);
imshow(img);
title('Original image');

subplot(2,4,5);
imshow(img);
title('Original image');


subplot(2,4,2);
imshow(img1);
title('Filtering by Matlab');

[counts1,x] = imhist(img);
subplot(2,4,3);
stem(x,counts1);
title('Before');


[counts2,x] = imhist(img1);
subplot(2,4,4);
stem(x,counts2);
title('After')


%lam min anh bang median filter
fp1 = fopen('KETQUA_ANH_2MEDIAN.txt','r');
A = fscanf(fp1, '%d %d', [512 512]);
fclose(fp1);
B = A.';
filtered_image = uint8(B);
subplot(2,4,6);
imshow(filtered_image);
title('Filtering by Algorithm');

[counts3,x] = imhist(img);
subplot(2,4,7);
stem(x,counts3);
title('Before');


[counts4,x] = imhist(filtered_image);
subplot(2,4,8);
stem(x,counts4);
title('After');
