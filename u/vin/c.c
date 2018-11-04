inherit ITEM;

void create()
{
        set_name("�鲼��", ({ "budai", "dai" }));
        set_weight(500);
        set_max_encumbrance(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һֻ���鲼֯�ɵĴ��ӣ��������װ������\n");
                set("value", 10);
        }
}

void init()
{
        object ob;
        seteuid(geteuid());
        add_action("do_where", "xun");
        add_action("quest_set1", "qset");
        add_action("quest_set2", "cset");
}

int do_where(string str)
{
        object me, ob, where, *ob_list;
        int i;

        if (! str)
                return notify_fail("ʲô��\n"); 

        me = this_player();
        ob = find_player(str);

        if (! ob) ob = find_living(str);
        if (! ob || ! me->visible(ob))
        {
                str = resolve_path(me->query("cwd"), str);
                ob = find_object(str);
        }

        if (! ob)
                return notify_fail("û���ҵ������Ʒ��\n");

        where = environment(ob);
        if (! where)
                return notify_fail("����˲�֪��������Ү...\n");

        write(sprintf("%s(%s)������%s(%s).\n",
                (string)ob->name(1),
                (string)ob->query("id"),
                (string)where->short(),
                (string)file_name(where)));
        return 1;
}

int quest_set1()
{
        object me = this_player();

        me->set("quest_count", 500);
        me->clear_condition();

        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        return 1;
}

int quest_set2()
{
        object me = this_player();

        me->add("quest_count", 99);
        me->clear_condition();

        me->set("neili", me->query("max_neili"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
        return 1;
}

int is_container()
{
        return 1;
}

int query_autoload()
{
        return 1;
}
