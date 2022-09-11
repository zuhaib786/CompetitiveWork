function [J, grad] = linearRegCostFunction(X, y, theta, lambda)
%LINEARREGCOSTFUNCTION Compute cost and gradient for regularized linear 
%regression with multiple variables
%   [J, grad] = LINEARREGCOSTFUNCTION(X, y, theta, lambda) computes the 
%   cost of using theta as the parameter for linear regression to fit the 
%   data points in X and y. Returns the cost in J and the gradient in grad

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost and gradient of regularized linear 
%               regression for a particular choice of theta.
%
%               You should set J to the cost and grad to the gradient.
%

a = X * theta;
cross_entropy = 1/(2*m) * (a - y)' * ( a- y);
cross_entropy_loss = sum(cross_entropy(:));
theta1 = theta(2:end, :);
reg_loss = lambda/(2*m) * ( theta1' * theta1);
J = cross_entropy_loss + reg_loss;
grad = 1/m * X' * (a - y) + lambda/m * [0; theta1];

% =========================================================================

grad = grad(:);

end
