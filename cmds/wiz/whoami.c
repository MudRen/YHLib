// whoami.c

int main(object me)
{
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

	write("��� User ID = " + getuid(this_player()) + "\n" );
	write("��� Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}

int help (object me)
{
write(@HELP
ָ���ʽ : whoami 

Show ����� User ID �� Effective User ID ��
HELP
     );
    return 1;
}
