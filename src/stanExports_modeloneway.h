// Generated by rstantools.  Do not edit by hand.

/*
    AnovaBYow is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AnovaBYow is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AnovaBYow.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_modeloneway_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_modeloneway");
    reader.add_event(29, 27, "end", "model_modeloneway");
    return reader;
}
#include <stan_meta_header.hpp>
class model_modeloneway
  : public stan::model::model_base_crtp<model_modeloneway> {
private:
        int N;
        int J;
        std::vector<int> predictor;
        vector_d response;
public:
    model_modeloneway(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_modeloneway(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_modeloneway_namespace::model_modeloneway";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "J", "int", context__.to_vec());
            J = int(0);
            vals_i__ = context__.vals_i("J");
            pos__ = 0;
            J = vals_i__[pos__++];
            check_greater_or_equal(function__, "J", J, 0);
            current_statement_begin__ = 5;
            validate_non_negative_index("predictor", "N", N);
            context__.validate_dims("data initialization", "predictor", "int", context__.to_vec(N));
            predictor = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("predictor");
            pos__ = 0;
            size_t predictor_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < predictor_k_0_max__; ++k_0__) {
                predictor[k_0__] = vals_i__[pos__++];
            }
            size_t predictor_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < predictor_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "predictor[i_0__]", predictor[i_0__], 1);
                check_less_or_equal(function__, "predictor[i_0__]", predictor[i_0__], J);
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("response", "N", N);
            context__.validate_dims("data initialization", "response", "vector_d", context__.to_vec(N));
            response = Eigen::Matrix<double, Eigen::Dynamic, 1>(N);
            vals_r__ = context__.vals_r("response");
            pos__ = 0;
            size_t response_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < response_j_1_max__; ++j_1__) {
                response(j_1__) = vals_r__[pos__++];
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 9;
            validate_non_negative_index("eta", "J", J);
            num_params_r__ += J;
            current_statement_begin__ = 10;
            num_params_r__ += 1;
            current_statement_begin__ = 11;
            num_params_r__ += 1;
            current_statement_begin__ = 12;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_modeloneway() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 9;
        if (!(context__.contains_r("eta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable eta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("eta");
        pos__ = 0U;
        validate_non_negative_index("eta", "J", J);
        context__.validate_dims("parameter initialization", "eta", "vector_d", context__.to_vec(J));
        Eigen::Matrix<double, Eigen::Dynamic, 1> eta(J);
        size_t eta_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
            eta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(eta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable eta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 10;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 11;
        if (!(context__.contains_r("sigmaalpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigmaalpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigmaalpha");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigmaalpha", "double", context__.to_vec());
        double sigmaalpha(0);
        sigmaalpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigmaalpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigmaalpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 12;
        if (!(context__.contains_r("sigmaepsilon")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigmaepsilon missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigmaepsilon");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigmaepsilon", "double", context__.to_vec());
        double sigmaepsilon(0);
        sigmaepsilon = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigmaepsilon);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigmaepsilon: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 9;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> eta;
            (void) eta;  // dummy to suppress unused var warning
            if (jacobian__)
                eta = in__.vector_constrain(J, lp__);
            else
                eta = in__.vector_constrain(J);
            current_statement_begin__ = 10;
            local_scalar_t__ mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.scalar_constrain(lp__);
            else
                mu = in__.scalar_constrain();
            current_statement_begin__ = 11;
            local_scalar_t__ sigmaalpha;
            (void) sigmaalpha;  // dummy to suppress unused var warning
            if (jacobian__)
                sigmaalpha = in__.scalar_lb_constrain(0, lp__);
            else
                sigmaalpha = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 12;
            local_scalar_t__ sigmaepsilon;
            (void) sigmaepsilon;  // dummy to suppress unused var warning
            if (jacobian__)
                sigmaepsilon = in__.scalar_lb_constrain(0, lp__);
            else
                sigmaepsilon = in__.scalar_lb_constrain(0);
            // transformed parameters
            current_statement_begin__ = 15;
            validate_non_negative_index("a", "J", J);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> a(J);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 16;
            validate_non_negative_index("yhat", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> yhat(N);
            stan::math::initialize(yhat, DUMMY_VAR__);
            stan::math::fill(yhat, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 18;
            stan::math::assign(a, add(mu, multiply(sigmaalpha, eta)));
            current_statement_begin__ = 20;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 21;
                stan::model::assign(yhat, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            get_base1(a, get_base1(predictor, i, "predictor", 1), "a", 1), 
                            "assigning variable yhat");
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 15;
            size_t a_j_1_max__ = J;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(a(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: a" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable a: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 16;
            size_t yhat_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < yhat_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(yhat(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: yhat" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable yhat: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 24;
            lp_accum__.add(normal_log<propto__>(eta, 0, 1));
            current_statement_begin__ = 26;
            lp_accum__.add(normal_log<propto__>(response, yhat, sigmaepsilon));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("eta");
        names__.push_back("mu");
        names__.push_back("sigmaalpha");
        names__.push_back("sigmaepsilon");
        names__.push_back("a");
        names__.push_back("yhat");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_modeloneway_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> eta = in__.vector_constrain(J);
        size_t eta_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
            vars__.push_back(eta(j_1__));
        }
        double mu = in__.scalar_constrain();
        vars__.push_back(mu);
        double sigmaalpha = in__.scalar_lb_constrain(0);
        vars__.push_back(sigmaalpha);
        double sigmaepsilon = in__.scalar_lb_constrain(0);
        vars__.push_back(sigmaepsilon);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 15;
            validate_non_negative_index("a", "J", J);
            Eigen::Matrix<double, Eigen::Dynamic, 1> a(J);
            stan::math::initialize(a, DUMMY_VAR__);
            stan::math::fill(a, DUMMY_VAR__);
            current_statement_begin__ = 16;
            validate_non_negative_index("yhat", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> yhat(N);
            stan::math::initialize(yhat, DUMMY_VAR__);
            stan::math::fill(yhat, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 18;
            stan::math::assign(a, add(mu, multiply(sigmaalpha, eta)));
            current_statement_begin__ = 20;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 21;
                stan::model::assign(yhat, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            get_base1(a, get_base1(predictor, i, "predictor", 1), "a", 1), 
                            "assigning variable yhat");
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t a_j_1_max__ = J;
                for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                    vars__.push_back(a(j_1__));
                }
                size_t yhat_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < yhat_j_1_max__; ++j_1__) {
                    vars__.push_back(yhat(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_modeloneway";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t eta_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "eta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmaalpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmaepsilon";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t a_j_1_max__ = J;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t yhat_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < yhat_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "yhat" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t eta_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "eta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmaalpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigmaepsilon";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t a_j_1_max__ = J;
            for (size_t j_1__ = 0; j_1__ < a_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "a" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t yhat_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < yhat_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "yhat" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_modeloneway_namespace::model_modeloneway stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
