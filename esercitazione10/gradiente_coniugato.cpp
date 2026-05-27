#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(int argc, char **argv) 
{
  const double tol = 1.0e-15;
  unsigned int n = 10; 
  
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
  if (abs(B.determinant()) < tol)
    return -1;

  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_ex;

  //
  Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
  Eigen::VectorXd r = b - A * x; 
  Eigen::VectorXd p = r;         
  
  double res_norm_0 = r.norm();

  const unsigned int it_max = 10000;
  unsigned int it = 0;
  const double res_tol = 1.0e-12;

  std::cout.precision(2);
  std::cout << std::scientific << "Matrix Cond: " << condA(A) << "\n";

  
  while (it < it_max && r.norm() > res_tol * res_norm_0)
  {
    
    Eigen::VectorXd Ap = A * p;
    double p_Ap = p.dot(Ap); 
    double alpha_k = p.dot(r) / p_Ap;
    x = x + alpha_k * p;
    r = b - A * x;
    double beta_k = p.dot(A * r) / p_Ap;
    p = r - beta_k * p;
    it++;
  }

  const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
                                              (x - x_ex).norm() / x_ex.norm();

  std::cout.precision(4);
  std::cout << std::scientific << "it" << "/" << "it_max" << "\n";
  std::cout << std::scientific << it << "/" << it_max << "\n";
  std::cout << std::scientific << "res" << "/" << "res_tol" << "\n";
  std::cout << std::scientific << r.norm() / res_norm_0 << "/" << res_tol << "\n";
  std::cout << std::scientific << "err_rel" << "\n";
  std::cout << std::scientific << err_rel << "\n";
  std::cout << std::scientific << "soluzione" << "\n";
  std::cout << std::scientific << x << "\n";

  return 0;
}