# CPP_PerfectForwarding
# Universal References (now known as Forwarding References):
In C++, universal references (a term coined by Scott Meyers, now officially recognized as forwarding references) are a type of reference that can bind to both lvalues and rvalues. They are denoted by T&& in template code and can either become lvalue references or rvalue references based on the type of the argument passed to the template function. They are key to implementing perfect forwarding.

# Perfect Forwarding: 
Perfect forwarding refers to the ability of a function to forward its arguments to another function, while maintaining each argument's lvalue or rvalue nature. This is achieved in C++ by using a combination of template functions, forwarding references (T&&), and the std::forward utility. Perfect forwarding is useful for creating template functions that take arbitrary arguments and pass them onto other functions that take those exact arguments.

# Reference Removal: 
Reference removal is the process of obtaining the underlying type when given a reference type. The type traits std::remove_reference and std::remove_reference_t are often used for this purpose in C++. For example, given a type T as int& or int&&, std::remove_reference<T>::type or std::remove_reference_t<T> would give you int.

# Reference Collapsing: 
 Reference collapsing is a rule in C++ that applies when you end up with a reference to a reference, which can happen during template instantiation or with the use of decltype. In C++ there is no such thing as a reference to a reference, so the reference collapsing rules are applied:

T& & becomes T&
T& && becomes T&
T&& & becomes T&
T&& && becomes T&&
