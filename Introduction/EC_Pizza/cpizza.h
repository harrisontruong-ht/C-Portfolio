// ============================================================================
// File: cpizza.h
// ============================================================================
// Programmer: Luciano Rodriguez
// Date: 11/23/25
//
// Description:
//      This is the header file for the CPizza class.
// ============================================================================

class CPizza
{
        public:

        CPizza();//default constructor
        CPizza(int large, int medium, int small); //type constructor
        CPizza(CPizza &cpy); //copy constructor


        void promptOrder();
        void calcCost();
        void dispOrder();

        private:

        int m_large;
        int m_medium;
        int m_small;
        double m_cost = 0.00;
        bool m_delivery = false;
        char m_name[256] = "Clark Kent";
        const double m_deliveryFee = 5.00;
};
