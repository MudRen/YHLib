// story:witer ʥ��

#include <ansi.h>

inherit F_CLEAN_UP;

mixed random_gift();

static mixed *story = ({
        "�캢�������������²����ˣ���ɮ�������ǻ��ˡ�",
        "������Ŷ����������Ӧ������ׯ�ۣ�����ʲô�£�",
        "�캢����������������ׯ����͵������Ԫ���ɵ��˲ι���",
        "����������������£��������д���",
        "�캢�����������ǻ��Ʒ�����Ԫ���ɵ��˲ι�����",
        "�������Ҳ�Ҫ���������´λ㱨������ʱ���ܷ����Ҫ����������ǰ�棿",
        "�캢����Ŷ��",
        "���������ص��ģ�ֻҪ����ʥˮһ��أ���ľҲ���Իش���",
        "���δ�",
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
        mapping my;

        obs = filter_array(all_interactive(), (: ! wizardp($1) &&
                                                 environment($1) &&
                                                 environment($1)->query("outdoors") &&
                                                 ! $1->query("doing") :));
        if (! sizeof(obs))
                return 0;

        ob = obs[random(sizeof(obs))];
        
        if (ob->query("gift/water") || random(5))
        {
                msg = HIW "ֻ��" + ob->name(1) +
                      HIW "ȫ���â��ҫ��������ȡ�" NOR;
 
                my = ob->query_entire_dbase();
                my["jing"]   = my["eff_jing"]   = my["max_jing"];
                my["jingli"] = my["eff_jingli"] = my["max_jingli"];
                my["qi"]     = my["eff_qi"]     = my["max_qi"];
                my["neili"]  = my["max_neili"];
                my["food"]   = ob->max_food_capacity();
                my["water"]  = ob->max_water_capacity();
        } else
        {
                msg = HIC "���Ǽ�" + ob->name(1) +
                      HIC "ȫ����â���֣���̨��⻪��˸�����������" NOR;
                ob->add("int", 1);
                ob->add("gift/water", 1);
        }
        return msg;
}

