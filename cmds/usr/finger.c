// finger.c

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object *ob;

        if (time() - me->query_temp("scan_time") < 10
           && ! wizardp(me))
                return notify_fail("�ȵȣ�ϵͳ�����С���\n");

        if (! arg)
        {
                if ((int)me->query("jing") < 50)
                        return notify_fail("��ľ����޷����С�\n");

                me->receive_damage("jing", 50);
                me->set_temp("scan_time", time());
                me->start_more(FINGER_D->finger_all());
        } else
        if (arg == "-m")
        {
                if (! wizardp(this_player()))
                        return notify_fail("����Ȩʹ�� -m ������\n");

                ob = filter_array(users(), (: $1->name() != $1->name(1) :));
                me->set_temp("scan_time", time());
                me->start_more(FINGER_D->user_list(ob), 0);
        } else
        {
                if ((int)me->query("jing") < 20)
                        return notify_fail("��ľ����޷����С�\n");

                me->set_temp("scan_time", time());
                write(FINGER_D->finger_user(arg));
        }
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ��finger [-m] [ʹ��������]
 
���ָ����û��ָ��ʹ��������������ʾ�����������������
���������ϡ���֮�������ʾ�й�ĳ����ҵ����ߣ�Ȩ�޵����ϡ�
���ʹ���� -m �����������г�ʹ����ߵ���ҡ�
 
���ָ�who
HELP);
        return 1;
}
