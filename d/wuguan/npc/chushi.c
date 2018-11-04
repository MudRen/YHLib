#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("��ʦ", ({ "chu shi", "chu", "shi" }));
        set("long", "���ǹ����ĳ��ӣ��غ���ʵ�����������Ҫ(serve)Щ�Եġ�\n");
        set("gender", "����");
        set("age", 65);
        set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_serve", "serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me = this_player();

        if (present("rice", me)
           && present("tea", me))
                return notify_fail(CYN "��ʦ���������ϲ��ǻ���ô������"
                                   "�����ã����˷�ʳ�\n" NOR);

        if (objectp(present("rice", environment(me)))
           && objectp(present("tea", environment(me))))
                return notify_fail(CYN "��ʦ��������Χ���ǻ���ô������"
                                   "�����ã����˷�ʳ�\n" NOR);


        message_vision(HIC "\n��ʦ���������ڵķ��˵ݵ�$N" HIC "���У�Ц"
                       "���������á�\n\n" NOR, me);
        food = new("/d/wuguan/obj/rice");
        water = new("/d/wuguan/obj/tea");
        food->move(me);
        water->move(me);

        return 1; 
}
