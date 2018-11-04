// summon command.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string str;
	int i;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return "/cmds/usr/summon"->main(me, arg);;

	if (! arg)
                return notify_fail("ָ���ʽ: Summon <player id> | <object>\n");

	str = arg;
	ob = find_player(str);
	if (! ob) ob = MESSAGE_D->find_user(str);
        if (objectp(ob) && ! me->visible(ob))
                ob = 0;
        if (! ob) ob = find_object(str);
	if (! ob)
        {
		str = resolve_path(me->query("cwd"), str);
		if (! sscanf(str, "%*s.c")) str += ".c";
                ob = find_object(str);
        }
	if (! ob)
		return "/cmds/usr/summon"->main(me, arg);

        if (wiz_level(ob) > wiz_level(me))
                return notify_fail("���߰���\n");

        if (environment(ob) == environment(me))
                return notify_fail("��... ����������ǰ��\n");

        if (environment(ob) == me)
                return notify_fail("��... ��������������\n");

        if (! me->is_admin())
        {
                switch (SECURITY_D->query_site_privilege("summon"))
                {
                case "all":
                        break;

                case "noneuser":
                        if (playerp(ob))
                                return notify_fail("�㲻�ܶ����ʩչ������\n");
                        break;

                case "user":
                        if (! playerp(ob))
                                return notify_fail("��ֻ�ܶ����ʩչ������\n");
                        break;

                default:
                        return notify_fail("�㲻��ʹ�ø����\n");
                }
        }

	// moving
	tell_room(environment(ob), HIM "��������һֻ���ְ�"+
	          (string)ob->query("name") + HIM "ץ������, Ȼ�᲻���ˡ�\n" NOR, ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
        tell_object(me, HIM "���" + ob->name() + HIM "ץ�������ǰ��\n" NOR);
	tell_object(ob, HIM ".... ����ʱ������" + me->name() + HIM
	            "����Ū�����ġ�\n" NOR);
	tell_room(environment(me), HIM + ob->name() + HIM "ͻȻ����" +
	          "������ǰ��\n" NOR, ({ me, ob }));

	ob->move(environment(me));

	// ok ..
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : summon <ĳ��> | <��Ʒ>

��ָ�������(��)��ĳ�˻���Ʒץ������ǰ��

�������ڿ��Ա���Ȩʹ�õ���Ϣ������noneuser, user��all��
HELP );
        return 1;
}
