//recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_rec;
        mapping family;
        int i;
        string temp;
        int student_num;

        if (! arg) return notify_fail("ָ���ʽ��recruit|shou [cancel]|<����>\n");

        if (arg == "cancel")
        {
                old_rec = me->query_temp("pending/recruit");
                if (! objectp(old_rec))
                        return notify_fail("�����ڲ�û����¼�κ���Ϊ���ӵ���˼��\n");

                write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
                tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
                me->delete_temp("pending/recruit");
                return 1;
        }

        if (! (ob = present(arg, environment(me))))
        	return notify_fail("������˭�����ӣ�\n");

        if (ob == me) return notify_fail("���Լ�Ϊ���ӣ������⡭������û���á�\n");

        if (ob->is_apprentice_of(me))
        {
                message_vision(CYN "$N" CYN "����$n" CYN "��ͷ��˵��������"
                               "ͽ������\n" NOR, me, ob);
                return 1;
        }

        if (! me->query("family"))
                return notify_fail("�㲢�������κ����ɣ�������ȼ���һ��"
			           "���ɣ����Լ���һ\n��������ͽ��\n");

        // If the target is willing to apprentice us already, we do it.
        if ((object)ob->query_temp("pending/apprentice") == me)
        {
                if (! living(ob))
                {
                        message_vision("$N������$nΪ���ӡ�\n\n" HIY "����"
                                       "������$n" HIY "��Ȼû�а취�а�ʦ"
                                       "֮��\n\n" NOR, me, ob);
                        return 1;
                }

                if (mapp(ob->query("family")) &&
                    (string)me->query("family/family_name") !=
                    (string)ob->query("family/family_name"))
                {
                        message_vision(HIR "$n" HIR "������ʦͶ��$N" HIR
                                       "���¡�\n" NOR + HIC "$n" HIC "��"
                                       "��������$N" HIC "���������ؿ�����"
                                       "����ͷ���е�����ʦ������\n" NOR,
                                       me, ob);
			ob->set("weiwang", 0);
			ob->set("gongxian", 0);
			ob->add("betrayer/times", 1);
                        ob->delete("quest");
                        ob->delete_temp("quest");
                        if (ob->query("family/family_name"))
                            ob->add("betrayer/" + ob->query("family/family_name"), 1);
                } else
                        message_vision(HIY "$N" HIY "������$n" HIY "Ϊ����"
                                       "��\n" NOR + HIC "$n" HIC "��������"
                                       "��$N" HIC "���������ؿ����ĸ���ͷ��"
                                       "�е�����ʦ������\n" NOR, me, ob);
        
                me->recruit_apprentice(ob);
                ob->delete_temp("pending/apprentice");
        
                write("\n��ϲ��������һ�����ӣ�\n");
                family = ob->query("family");
                tell_object(ob, sprintf("\n��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n",
                            family["family_name"],
                            chinese_number(family["generation"]) ));
                return 1;
        } else
        {
                old_rec = me->query_temp("pending/recruit");
                if (ob == old_rec)
                        return notify_fail("������" + ob->name() + "Ϊ���ӣ����ǶԷ���û�д�Ӧ��\n");
                else
                if (objectp(old_rec))
                {
                        write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
                        tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
                }
                me->set_temp("pending/recruit", ob );
                message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", me, ob);
                tell_object(ob, YEL "�����Ը���" + me->name() + "Ϊʦ����"
		                "�� apprentice ָ�\n" NOR);
                return 1;
        }
}


int help(object me)
{
        write(@HELP
ָ���ʽ : recruit|shou [cancel]|<����>

���ָ����������ĳ��Ϊ����, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.

See Also:       apprentice
HELP );
        return 1;
}
