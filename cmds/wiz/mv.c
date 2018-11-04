// mv.c
// updated by doing
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        seteuid(geteuid(me));
        if (! arg || sscanf(arg, "%s %s", src, dst) != 2)
		return notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if (file_size(src) == -1)
                return notify_fail("Դ�ļ����ִ���\n");

        if (! rename(src, dst))
                write("Ok.\n");
        else
                write("��û���㹻�Ķ�дȨ����\n");
        return 1;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : mv <ԭ����> <Ŀ�굵��>
 
��ָ��������޸�ĳ��������Ŀ¼���ơ�

see also: cp, rm
HELP );
    return 1;
}
