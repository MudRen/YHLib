#include <ansi.h>
inherit NPC;

mixed ask_tanqin();
mixed ask_stop();

void create()
{
        set_name("�ٲ���", ({ "qin caizi", "qin", "caizi" }));
        set("long", "Сͯ��\n");
        set("gender", "����");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("combat_exp", 100000);

        set_skill("tanqin-jifa", 300);
        set_skill("qiuyue-lai", 300);
        set_skill("literate", 300);
        map_skill("tanqin-jifa", "qiuyue-lai");

        set("tattoo/face_long", "һ̨������");

        set("inquiry", ([
                "����" : (: ask_tanqin :),
                "ֹͣ" : (: ask_stop :),
        ]));

        setup();

        carry_object("clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/henshan/yueqi/jiuxiaoqin"));
}

mixed ask_tanqin()
{
        object me;

        me = this_player();

        if (me->query("id") != "vinwf")
                return RANK_D->query_respect(me) + "�������ز���"
                       "ʶ����֪���ԴӺ�˵��";

        if (query("tanqin"))
                return "���������ڵ��٣����������ˡ�";

        command("nod");
        command("play qiuyue-lai");
        set("tanqin", 1);

        remove_call_out("tanqin");
        call_out("tanqin", 2, me);
        return 1;
}

mixed ask_stop()
{
        object me;

        me = this_player();

        if (! query("tanqin"))
                return "������û�ڵ��ٰ���";

        if (me->query("id") != "vinwf")
                return RANK_D->query_respect(me) + "�������ز���"
                       "ʶ����֪���ԴӺ�˵��";

        command("nod");

        delete("tanqin");
        return 1;
}

void tanqin(object me)
{ 
        if (! query("tanqin"))
                return;

        command("play qiuyue-lai");

        remove_call_out("tanqin");
        call_out("tanqin", 2, me);
        return;
}
