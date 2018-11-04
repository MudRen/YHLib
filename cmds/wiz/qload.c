// qload.c

inherit F_CLEAN_UP;

int main(object me)
{
    if (! SECURITY_D->valid_grant(me, "(wizard)"))
            return 0;

    write(query_load_average() + "\n");
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : qload 

���ָ����ʾ��Ŀǰ CPU �ĸ���, cmds/s ��ÿ����뼸�� cmds
comp lines/s ��ÿ�뼸�С�
HELP
    );
    return 1;
}
