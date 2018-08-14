function x=Tridiag(e,f,g,r)
% Tridiag: Tridiagonal equation solver banded system
% ATTENTION: e,f,g,r must have the same size(using 0)
%            This method is especially useful when solving the 
%            conservation law problems.
%  x=Tridiag(e,f,g,r): Tridiagonal system solver
% input:
%  e=subdiagonal vector
%  f=diagnoal vector
%  g=superdiagonal vector
%  r=right hand side vector
% output:
%  x=solution vector
n=length(f);
% forward elimination
for k=2:n
    factor=e(k)/f(k-1);
    f(k)=f(k)-factor*g(k-1);
    r(k)=r(k)-factor*r(k-1);
end
% back substitution
x(n)=r(n)/f(n);
for k=n-1:-1:1
    x(k)=(r(k)-g(k)*x(k+1))/f(k);
end