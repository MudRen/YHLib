// master.c

#include <dbase.h>
#include <login.h>
#include <ansi.h>

int prevent_learn(object me, string skill)
{
	mapping fam;

	if (! me->is_apprentice_of(this_object()) &&
	    mapp(fam = me->query("family")) &&
            fam["family_name"] == query("family/family_name"))
	{
		command("say ��Ȼ��Ϊ�����µ��ӣ���ȴ���ҵմ�"
                        "������ȥ����ʦ��ѧ�ɡ�");
                return 1;
	}

	return 0;
}

void attempt_detach(object me)
{
        if (! me->is_apprentice_of(this_object()))
        {
                command("say �߿������ֲ�����ʦ�����������ҡ�");
                return;
        }

        command("sigh");
        command("say ��Ȼ��ˣ���Ҳ����ǿ�������߰ɣ�");
        command("say ������֮ǰ����Ȱ���ѧ�����书���£�");

        message_vision(HIY "\n$N" HIY "һ����ȣ���Ȼһָ����"
                       "��$n" HIY "��̴�д�Ѩ�ϡ�\n\n" NOR +
                       CYN "$N" CYN "˵������������ѧ���书��"
                       "�Ѹ���ϵ������պ���������ʦͽ֮�ݡ�\n"
                       NOR, this_object(), me);

        me->skill_expell_penalty();
        me->unconcious();
	me->add("detach/" + me->query("family/family_name"), 1);
	me->delete("family");
	me->set("gongxian", 0);
        me->delete("quest");
        me->delete_temp("quest");
	me->set("title", "��ͨ����");
}

