#include "hiker.hpp"


Knapsack::Knapsack(int p_limitWeight,VECGOODS p_vg):m_limitWeight(p_limitWeight),
                                                    m_vg(p_vg)
{
}


int Knapsack::findKnapsack()
{
    return getValue(m_vg.size()-1,m_limitWeight);
}

int Knapsack::getValue(int num,int leftWeight)
{
    if(num < 0 or leftWeight <=0)
    {
        return 0;
    }

    if(leftWeight < m_vg[num].first)
    {
        return getValue(num-1,leftWeight);
    }
    else
    {
        return std::max(getValue(num-1,leftWeight-m_vg[num].first) + m_vg[num].second,getValue(num-1,leftWeight));
    }

}