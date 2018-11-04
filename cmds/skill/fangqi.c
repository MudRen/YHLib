// abandon.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int skill_lvl, lvl;
    	int jingcost;
	string skill;
    	string name;
        int lost;

	if(! arg || arg == "" || sscanf(arg, "%s", skill) != 1)
		return notify_fail("��Ҫ�������黹��ĳһ��ܣ�\n");

    	if (me->is_fighting())
        	return notify_fail("����æ�Ŵ���أ�����ʱ���������£�\n");

    	if (me->is_busy())
        	return notify_fail("����æ��û������������\n");

    	jingcost = me->query("int") + random(me->query("int"));
    	if (jingcost > me->query("jing"))
        	return notify_fail("���޷����о�����\n");

        if (skill == "exp")
        {
                lost = me->query("combat_exp");
                if (lost < 100)
                        return notify_fail("�㷢���Լ����ڶ���ѧ��ֱ����һ����֪��\n");

                message("vision", me->name() + "����������˼��ʲô��\n",
                        environment(me), me);
                tell_object(me, "�㲻����ȭ�ű����Ṧ�ڹ���ֻ��һ����˼�����书��\n");
                me->start_busy(3 + random(5));
                if (random(me->query("int")) > 10)
                {
                        tell_object(me, "�����㷢���Լ��ƺ�����̫�ã�û�а��Ч����\n");
                        return 1;
                }

                lost = random(lost / 100) + 1;
                me->add("combat_exp", -lost);
                switch (random(6))
                {
                case 0:
                        tell_object(me, HIR "���������˺ܶ���ܰ"
                                    "�����£����ɵó������С�\n" NOR);
                        break;
                case 1:
                        tell_object(me, HIR "���ƺ��ֿ�����ңԶ"
                                    "��ͯ�꣬һʱ��ȴ�˳�����ķ��ա�\n" NOR);
                        break;
                case 2:
                        tell_object(me, HIR "����Ȼһ����̾��ֻ��"
                                    "���Լ�Ϊ����ѧ�ķ�һ����ʵ����ν��\n" NOR);
                        break;
                case 3:
                        tell_object(me, HIR "������ֹˮ�����е�"
                                    "�书���·����Լ�Զȥ�ˡ�\n" NOR);
                        break;
                case 4:
                        tell_object(me, HIR "��̧ͷ������գ���"
                                    "��������͸����˵�����Ľ��ģ��������ľ㻯��\n" NOR);
                        break;
                case 5:
                        tell_object(me, HIR "���Ժ��лι�������"
                                    "���̿����������ӣ����ɵð��Կ�Ц��\n" NOR);
                        break;
                }

                UPDATE_D->check_user(me);
                return 1;
        }

    	name = to_chinese(skill);
    	if (name[0] < 160) name = "�����";
	skill_lvl = (int)me->query_skill(skill, 1);
	if (! skill_lvl)
	{
		me->delete_skill(skill);
		write("���ˡ�\n");
		return 1;
	}

    	me->start_busy(1 + random(me->query("int") / 7));
    	if (random(me->query("int")) > 24)
        	return notify_fail("�㼯�о���������" + name + "��������ֺ��޽����\n");

    	skill_lvl = random(skill_lvl);
    	if (skill_lvl < 1)
    	{
        	me->delete_skill(skill);
        	write("�㼯�о���������" + name + "��������ڽ������������ˡ�\n");
    	} else
    	{
        	me->set_skill(skill, skill_lvl);
        	write("�㼯�о���������" + name + "���������Ч����\n");
    	}
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������> | exp

�������ʵս�������ĳһ������ѧ���ļ��ܣ��ɹ��ʺ�����츳��
�أ�ֻ���ܹ���Ϣ�ĵط����ܹ��������������书�����������
�ܵ���Ϊ�Ƚϸߣ�һ�β�һ���ܹ����׵����ǡ�

��ʱ����Ϊ�书��˻����㲻�ٴ�����ĳ��������¹��򣬾Ϳ���
ʹ������ָ���������
TEXT );
	return 1;
}

