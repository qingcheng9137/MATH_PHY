function yi=LinearSpline(x,y,xx)
% Linear Spline:there are two steps:
%  1.binary search.To find the location of interpolated xx.
%  2.apply the linear interpolation

% ATTENTION:this program is for x is almostly continue,which 
%           means x(iM) is exist.If not,maybe unaccurary.
n=length(x);
if(xx<x(1)||xx>x(n))
    error('Interpolation outside the range')
end
% binary search
iL=1;iU=n;
while(1)
    if iU-iL<=1,break,end
    iM=fix((iL+iU)/2);
    if(xx<x(iM))
        iU=iM;
    else
        iL=iM;
    end
end
% linear interpolation
yi=y(iL)+(y(iL+1)-y(iL))/(x(iL+1)-x(iL))*(xx-x(iL));