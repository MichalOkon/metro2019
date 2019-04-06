#ifndef STRETCH_H
#define STRETCH_H


class stretch
{
    public:
        stretch();
        stretch(int id, int pass; station from; station to)
        {
            m_id = id;
            m_pass = pass;
            m_from = from;
            m_to = to;
        };
        virtual ~stretch();

        int Getid();
        void Setid(int val);
        int Getpass();
        void Setpass(int val);
        station Getfrom();
        void Setfrom(station val);
        station Getto();
        void Setto(station val);

    protected:

    private:
        int m_id;
        //maximum number of passengers transported at the same time
        int m_pass;
        station m_from;
        station m_to;
};

#endif // STRETCH_H
