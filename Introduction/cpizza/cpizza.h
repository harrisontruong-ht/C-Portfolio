// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: Harrison Truong
// Date: 11/30/25
//
// Description:
//      This is the header file for the CPizza class.
// ============================================================================

#ifndef CPIZZA_HEADER
#define CPIZZA_HEADER

// constant grade values
const   double  TAX = 0.0775;   // taxes
const   double  LPIZZA = 20.0;  // price of a large pizza
const   double  MPIZZA = 15.0;  // price of a medium pizza
const   double  SPIZZA = 10.0;  // price of a small pizza
const   double  DFEE = 5.0;     // delivery fee
const   int             LEN = 256; // name length

class   CPizza
{
public:
        // constructors
        CPizza(); // default
        CPizza(const char *ptrName, int LPizza = 0, int MPizza = 0, int SPizza = 0,
                   double cost = 0.0, bool delivery = false
                   ,double deliveryFee = DFEE); // type
        CPizza(CPizza &cpy); // copy
        ~CPizza(); // destructor

        // member functions
        void    SetLPizza(int numL){*m_LPizza = numL;}
        void    SetMPizza(int numM){*m_MPizza = numM;}
        void    SetSPizza(int numS){*m_SPizza = numS;}
        void    SetDelivery(bool deliv){*m_delivery = deliv;}
        void    SetDeliveryFee(double delivFee){*m_deliveryFee = delivFee;}
        void    SetName(const char *name);
        int             GetLPizza() const{return *m_LPizza;}
        int             GetMPizza() const{return *m_MPizza;}
        int             GetSPizza() const{return *m_SPizza;}
        bool    GetDelivery() const{return *m_delivery;}
        double  GetDeliveryFee() const{return *m_deliveryFee;}
        char    *GetName() const{return m_name;}
        double  GetTotal() const{return *m_cost;}
        void    CalcCost();
        void    DispOrder();


private:
        // data members
        int     *m_LPizza;
        int     *m_MPizza;
        int     *m_SPizza;
        double  *m_cost;
        bool    *m_delivery;
        double  *m_deliveryFee;
        char    *m_name;
};

#endif  // CPIZZA_HEADER
