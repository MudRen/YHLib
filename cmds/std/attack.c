// attack.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{

        // ���ָ�������⣬�����������ô�ָ���������������
        // ϵͳ��Դ�½�����д��ע���ͬʱ�Ѿ����������ڹ���
        // ��д����������������purge id��
        write("��ָ����ʱ�رգ�\n");
        return 1;
/*
	object ob, *inv;
	int i = 0;

	seteuid(getuid());

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��򶷣�\n");        

	if (me->query("jing") <= 30)
		return notify_fail("������̫���ˣ��޷���Ұ�ް���ҧ�ˡ�\n");

	if (! arg)
		return notify_fail("��Ҫ��ʲôҰ�ް���ҧ˭��\n");

	if (! objectp(ob = present(arg, environment(me))))
		return notify_fail("����û����������ɣ�\n");

	inv = all_inventory(environment(me));
	while (i < sizeof(inv) && i >= 0)
	{
                if (inv[i] == ob)
                        continue;

                if (! inv[i]->is_character() || inv[i]->query("can_speak"))
                        continue;

		if (inv[i]->query_temp("owner") == me)
		{
			if (inv[i]->is_fighting())
				return notify_fail("�Ѿ���Ұ���ڰ���ҧ���ˣ�\n");

			if (inv[i]->is_busy())
				return notify_fail(inv[i]->name() +
						   "����æ����û�����㣡\n");

			if (me->query_skill("training", 1) < 30)
				return notify_fail("���Ԧ�����������죬�޷�"
						   "��Ұ�ް���ҧ�ˣ�\n");

			message_vision("ֻ��$N����" +inv[i]->name()+
				       "����һ�����ڣ���һ�ܾ���$n������ȥ��\n",
				       me, ob);
			me->receive_damage("jing", 30);
                        me->want_kill(ob);
			inv[i]->fight_ob(ob);
			return 1;
		}
		i++;
	}

        write("����û���������ʹ�Ķ���\n");
	return 1;
*/
}

int help(object me)
{
	write(@HELP
ָ���ʽ : attack <����>

��ָ���������ĳ������㹥����ҧ���ˡ������Ѿ�ѱ���Ķ�����Խ���
����ָ�

����ָ�
        come <������>:                  �ö�����������ж���
        stay:                           ֹͣ����ĸ���״̬��
        attack <ĳ��>:                  �ö��﹥�����ˡ�
        stop <������>:                  �ö���ֹͣ���˵Ĺ�����
        release:                        ������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
        qi(ride) <������>:              ���������������ȡ�
        xia(unride) <������>:           �£��뿪���

HELP );
	return 1;
}
