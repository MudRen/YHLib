#include <ansi.h>
inherit NPC;

mixed ask_chuixiao();
mixed ask_stop();

void create()
{
        set_name("�����", ({ "xiao caizi", "xiao", "caizi" }));
        set("long", "��ԯ�е�Сͯ��\n");
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

        set_skill("chuixiao-jifa", 300); 
        set_skill("taohua-yuan", 300); 
        set_skill("literate", 300);
        map_skill("chuixiao-jifa", "taohua-yuan");

        set("tattoo/face_long", "һ������");

        set("inquiry", ([
                "����" : (: ask_chuixiao :),
                "ֹͣ" : (: ask_stop :),
        ]));

        setup();

        carry_object("clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/henshan/yueqi/zhuxiao-liuquan"));
}

mixed ask_chuixiao()
{
        object me;

        me = this_player();

        if (me->query("id") != "vin")
                return RANK_D->query_respect(me) + "�������ز���"
                       "ʶ����֪���ԴӺ�˵��";

        if (query("chuixiao"))
                return "���������ڴ�����������ˡ�";

        command("nod");
        command("play taohua-yuan");
        set("chuixiao", 1);

        remove_call_out("chuixiao");
        call_out("chuixiao", 2, me);
        return 1;
}

mixed ask_stop()
{
        object me;

        me = this_player();

        if (! query("chuixiao"))
                return "������û�ڴ��ﰡ��";

        if (me->query("id") != "vin")
                return RANK_D->query_respect(me) + "�������ز���"
                       "ʶ����֪���ԴӺ�˵��";

        command("nod");

        delete("chuixiao");
        return 1;
}

void chuixiao(object me)
{ 
        if (! query("chuixiao"))
                return;

        command("play taohua-yuan");

        remove_call_out("chuixiao");
        call_out("chuixiao", 2, me);
        return;
}
