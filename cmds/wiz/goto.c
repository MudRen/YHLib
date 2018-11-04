// goto.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj;
        object env;
	string msg;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

	if (! arg) return notify_fail("��Ҫȥʲô�ط���\n");

	if (sscanf(arg, "-i %s", arg)) goto_inventory = 1;

	if (! arg) return notify_fail("��Ҫȥ���\n");

	obj = find_player(arg);
	if (! obj) obj = MESSAGE_D->find_user(arg);
	if (! obj) obj = find_living(arg);
	if (! obj || ! me->visible(obj))
	{
		arg = resolve_path(me->query("cwd"), arg);
		if (! sscanf(arg, "%*s.c") ) arg += ".c";
		if (! (obj = find_object(arg)))
		{
			if (file_size(arg)>=0)
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}

	if (! goto_inventory)
        {
                if (environment(obj))
		        obj = environment(obj);
                else
                {
                        if (obj->is_character())
                                // unless you goto a inventory, or you
                                // can not enter a character
                                obj = 0;
                }
        }

	if (! obj) return notify_fail("������û�л������� goto��\n");

        if ((env = environment(me)) == obj)
                return notify_fail("����ԭ���ұ�ʲô��\n");

        if (obj == me)
                return notify_fail("�������������굽�Լ��������棿\n");

        if (me->query("gender") == "Ů��" )
                tell_object(me, HIG "�㻯������ȥ��\n" NOR);
        else
                tell_object(me, HIY "�㻯�������ȥ��\n" NOR);
                
	if (env && ! me->query("env/invisible"))
	{
        	if (! stringp(msg = me->query("env/msg_mout")))
                        msg = "ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�";

                msg = replace_string(msg, "$N", me->name() + HIM);
               	message("vision", HIM + msg + "\n" NOR, env, ({ me, env }));
        }

        me->set_magic_move();
        if (! me->move(obj))
        {
                msg = HIM "��Ķ���ʧ���ˡ�\n" NOR;
                tell_object(me, msg);
                message("vision", HIM "ͻȻ" + me->name() + "һ����ͷ"
                                  "ˤ���ڵ��ϡ�\n" NOR, obj, ({ me }));
                return 1;
        }
        else
                msg = HIM "�㵽�˵ط������¶ݹ⣬��ס���Ρ�\n" NOR;

	if (environment(me) != obj)
		return 1;

        tell_object(me, msg);

	if (! me->query("env/invisible"))
	{
		if (! stringp(msg = me->query("env/msg_min")))
			msg = "$N����ӰͻȻ������һ������֮�С�";
                msg = replace_string(msg, "$N", me->name());
               	message("vision", HIM + msg + "\n" NOR, obj, ({ me, obj }));
	}

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : goto [-i] <Ŀ��>
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.
 
HELP );
        return 1;
}
