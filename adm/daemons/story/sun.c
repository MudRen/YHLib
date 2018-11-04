// story:sun �ճ�

#include <ansi.h>

inherit F_CLEAN_UP;

mixed random_gift();

static mixed *story = ({
        "���ࣺ�����ܣ�",
        "���ڣ���⣬���±��޿ɱܣ�����ô�죿",
        "���ࣺ������",
        "��ಡ�����",
        "���ڣ���ɱ�ģ�����ͺ���ƴ�ˣ�",
        "���ࣺ�����ˣ����ҵġ��ٲ���������",
        "���ڣ�������֮�⡹��",
        "��ಡ���ಡ�����",
        "���ڣ����ϡ���",
        "��������������������",
        "����Ĩ��Ĩ�������գ�",
        (: random_gift :),
});

void create()
{
        seteuid(getuid());
}

string prompt() { return HIR "�������˻���" NOR; }

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

mixed random_gift()
{
        object *obs;
        object ob;
        string msg;

        obs = filter_array(all_interactive(), (: ! wizardp($1) &&
                                                 environment($1) &&
                                                 environment($1)->query("outdoors") &&
                                                 ! $1->query("doing") :));
        if (! sizeof(obs))
                return 0;

        ob = obs[random(sizeof(obs))];
        
        if (ob->query("gift/sun") || random(5))
        {
                msg = HIR + ob->name(1) + "һ���ҽУ�����ĵ�����ȥ��" NOR;
                if (ob->query("combat_exp") < 1000000 ||
                    ob->query("qi") < 1000)
                        ob->unconcious();
                else
                {
                        ob->set("qi", 10);
                        ob->set("eff_qi", 10);
                        ob->set("jing", 1);
                        ob->set("eff_jing", 1);
                }
        } else
        {
                msg = HIY "���Ǽ�" + ob->name(1) +
                      HIY "������������������Σ��������ݡ�" NOR;
                ob->add("str", 1);
                ob->add("gift/sun", 1);
        }
        return msg;
}

