
/* dcl: parse a declarator */
void dcl(void) {
    int ns;

    /* count *'s */
    for (ns = 0; gettoken() == '*';) {
        ns++;
    }
    dirdcl();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

/* dirdcl: parse a direct declarator */
void dirdcl(void) {
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype == ')')
    }
}