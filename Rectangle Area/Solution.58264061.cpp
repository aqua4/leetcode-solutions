class Solution {
public:
    int check(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (C<=G && C>=E && B<=H && B>=F) return (C-max(A,E))*(min(H,D)-B);
        if (A<=G && A>=E && B<=H && B>=F) return (min(G,C)-A)*(min(H,D)-B);
        if (A>=E && A<=G && D>=F && D<=H) return (min(G,C)-A)*(D-max(B,F));
        if (C<=G && C>=E && D<=H && D>=F) return (C-max(A,E))*(D-max(B,F));
        return 0;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans=(C-A)*(D-B)+(G-E)*(H-F);
        if (G<C && G>A && E<C && E>A && H>D && D>F) A=E;
        if (A>E && A<G && C>E && C<G && D>H && H>B) E=A;
        return ans-max(check(A,B,C,D,E,F,G,H),check(E,F,G,H,A,B,C,D));
    }
};