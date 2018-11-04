// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        string *killer, callname;

	if (me->is_chatter())
		return 0;

        if (environment(me)->query("no_fight"))
                return notify_fail("���ﲻ׼ս����\n");

        if (! arg)
                return notify_fail("����ɱ˭��\n");

        if (! objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if (! obj->is_character() || obj->is_corpse())
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if (obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:)��\n");

        if (arrayp(me->query_team()) &&
            member_array(obj, me->query_team()) != -1)
                return notify_fail("�����Լ������е���ҲҪɱ��̫���˵��˰ɣ�\n");

	if (me->is_fighting(obj) && me->is_killing(obj->query("id")))
		return notify_fail("�����ں��˼����������ء�\n");

        if ((int)obj->query_condition("die_guard"))
		return notify_fail("����������ٸ��������أ����Ǳ�ȥ���ǡ�\n");

        if (! me->is_fighting(obj) &&
            me->query("qi") < me->query("max_qi") * 3 / 10)
                return notify_fail("������û������ս���ˡ�\n");

        callname = RANK_D->query_rude(obj);

        if (obj->query("can_speak"))
        {
        	if (! living(obj))
            		message_vision(HIR "\n$N" HIR "���˿��ε��ڵص�$n" HIR "����Ц"
                                       "һ�����ȵ���" + callname + HIR  "�����Ҽ�����ȥ"
                                       "�ɣ�\n\n" NOR, me, obj);
            	else if (random(3) > 1)
            		message_vision(HIR "\n$N" HIR "����$n" HIR "�ȵ���" + callname +
                                       HIR  "�����ղ������������һ\n\n" NOR, me, obj);
            	else
            		message_vision(HIR "\n$N" HIR "����$n" HIR "�ȵ���" + callname +
                                       HIR "��������վ�����ļ��գ�\n\n" NOR, me, obj);
        }

        switch(obj->accept_kill(me))
	{
	case 0:
                return (! objectp(obj));
	case -1:
		return 1;
	default:
	}

        if (userp(me) && userp(obj) && ! obj->is_want_kill(me->query("id")))
                me->want_kill(obj);

        me->kill_ob(obj);
        if (living(obj) && ! userp(obj))
                obj->kill_ob(me);
        else
                obj->fight_ob(me);

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ����

�������ָ��: hit, fight

HELP);
        return 1;
}
