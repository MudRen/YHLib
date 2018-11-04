// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        mapping site_privilege;
        string item, desc;
        string msg;

        if (! is_root(me) && ! SECURITY_D->valid_grant(me, "(admin)"))
                return notify_fail("ֻ�й���Ա������Ȩ��վ���ʹ��Ȩ�ޡ�\n");

        if (! arg)
        {
                site_privilege = SECURITY_D->query_site_privilege();
                map_delete(site_privilege, INTERMUD_MUD_NAME);
                if (sizeof(site_privilege) < 1)
                {
                        write("Ŀǰ��վ��û�и����κ�ʹ��Ȩ�ޡ�\n");
                        return 1;
                }

                msg = "Ŀǰ��վ��(" + INTERMUD_MUD_NAME + ")�����ʹ��Ȩ����Ϣ���£�\n";

                foreach (item in keys(site_privilege))
                        msg += sprintf("%s : %s\n", item, site_privilege[item]);

                me->start_more(msg);
                return 1;
        }

        if (! me->is_admin())
                return notify_fail("�㲻���޸����վ���ʹ��Ȩ�ޡ�\n");

        if (sscanf(arg, "%s %s", item, desc) != 2)
        {
                item = arg;
                desc = 0;
        }

        if (desc == "0" || desc == "clear")
                desc = 0;

        if (! SECURITY_D->set_site_privilege(item, desc))
                return notify_fail("�޷����� " + item +
                                   " �����Ȩ����ϢΪ " + desc + "��\n");
        else
        if (! desc)
                write("����� " + item + " �����Ȩ����Ϣ��\n");
        else
                write("Ok.\n");

        SECURITY_D->save();
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: sp <class> <info>

��Ȩ������վ��ĳЩ�����ʹ��Ȩ�ޡ�info ���Ϊ�ջ��� clear ��
��ʾȡ�������ʹ��Ȩ�ޡ�
HELP );
        return 1;
}
