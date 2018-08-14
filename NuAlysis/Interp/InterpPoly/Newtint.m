function yint=Newtint(x,y,xx)
%            Written by Jerry Zheng
% *****************2018.5.3******************

% Newtint:Newton interpolating polynomial
% yint=Newtint(x,y,xx):Uses an (n-1)_order Newton
%  interpolating polynomial based on n data points(x,y)
%  to determine a value of the independent variable,xx.
% input:
%  x=independent variable
%  y=dependent variable
%  xx=value of the independent variable,at which 
%     interpolation is calculated
% ouput:
%  ying=interpolated value of dependent variable

n=length(x);
if n~=length(y), error ('Make sure x and y has the same dimension!'); end
b=zeros(0,0);
b(:,1)=y(:);
% compute the finite divided differences in the form of a
% difference table,and put them in the army
for j=2:n
    for i=1:n-j+1
        b(i,j)=(b(i+1,j-1)-b(i,j-1))/(x(i+j-1)-x(i));
    end
end
% use the finite divided differences to interpolate
xt=1;
yint=b(1,1);
for j=1:n-1
    xt=xt*(xx-x(j));
    yint=yint+b(1,j+1)*xt;
end
