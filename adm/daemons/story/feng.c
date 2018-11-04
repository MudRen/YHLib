// story:feng ����

#include <ansi.h>

mixed random_gift();

inherit F_CLEAN_UP;

static mixed *story = ({
        "·�ˣ���λ��磬�⸽�������ʲô��ֵ����鷢����",
        "�Է���˵������ߵĺ��Ͼ��������һֻ��ˡ�",
        "·�ˣ�ԭ����������....",
        "�Է򣺰������Ǹ��������ġ�",
        "·�ˣ���˵�ϻ����忴���˷�����裬��������ǣ�����Ѱ���˶��򲻹����ˡ�",
        "......",
        "���ߣ���˿���ˮ�еĵ�Ӱ���������Լ��������У��������衣",
        "��Χ���ŷ�����������硣",
        "����������",
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
        
        if (ob->query("gift/feng") || random(5))
        {
                msg = HIR + ob->name(1) + "��һ�������������ˤ���˵��ϡ�" NOR;
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
                msg = HIG "��˵" + ob->name(1) +
                      HIG "�����п����˷�����衣" NOR;
                ob->add("dex", 1);
                ob->add("gift/feng", 1);
        }
        return msg;
}

