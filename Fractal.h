#ifndef FRACTAL_H
#define FRACTAL_H

#include <vector>
#include <string>

class Fractal
{
protected:
    string Vars;
    string Consts;
    string Axiom;
    vector < pair <char, string> > rules;
public:
    Fractal(){}
    ~Fractal()
    {
        Vars.clear();
        Consts.clear();
        Axiom.clear();
        rules.clear();
    }
    void setSymbols(string Variables, string Constants)
    {
        Vars = Variables;
        Consts = Constants;
    }

    bool addRule(char var, string repl, bool overwrite = false)
    {
        if(Vars.find(var) < 0) return 0;
        pair<char,string> newRule (var,repl);

        for (int i=0; i<rules.size(); i++)
            if (var == rules[i].first && !overwrite)
                return 0;

        rules.push_back(newRule);
        return 1;
    }

    void setAxiom (string newAxiom)
    {
        Axiom = newAxiom;
    }


    string coresp(char ch)
    {
        for(int i=0; i< rules.size(); i++)
            if(ch == rules[i].first)
                return rules[i].second;

        for(int i=0; i< Consts.size(); i++)
            if(ch == Consts[i])
                {
                    string rez ;
                    rez += Consts[i];
                    return rez;
                }

        string newStr;
        return newStr;
    }

    void evolve ()
    {
        string newAxiom;
        for(int i=0; i< Axiom.size(); i++)
            newAxiom += coresp(Axiom[i]);
        Axiom.clear();
        Axiom = newAxiom;
    }

    string getAxiom() {return Axiom;}
};


#endif // FRACTAL_H
