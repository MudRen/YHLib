inherit NPC;
mixed ask_me();
#include <ansi.h>

void create()
{
        set_name("�����", ({ "zhuge buliang", "zhuge", "buliang" }) );
        set("gender", "����" );
        set("age", 35);
        set("per", 30);
        set("long", "һλ�����ڽ��ɷ���ǵ���ʿ��\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("literate", 200);

        set("chat_chance", 2);
        set("chat_msg",({
                CYN "�����̾����������֪���ģ����������о���γ��֮�ţ��κ�����֪����\n" NOR,
                CYN "���������Ҫ���һ������ǵ�����������������о�ɢ���ɡ�\n" NOR,
        }));
        setup();

        add_money("silver", 20);
        set("inquiry", ([
                "name"       : "������������֮�ڶ�ʮ�������������Ҳ��\n",
                "here"       : "���������ڣ������������֮��Ҳ��\n",
                "�����"     : "��������ֱ�����������䣿\n",
                "��������"   : "������֮����Ҳ���������ϻ�ƽ�����Ͻ����ʶ�������ȥ\n"
                               "�Ͻ����������������һ��֮����",
                "����"       : (: ask_me :),
                "�һ���"     : (: ask_me :),
                "����о�ɢ" : (: ask_me :),
        ]));
        carry_object("/d/city/obj/cloth")->wear();
}

mixed ask_me()
{
        object ob;
        object me = this_player();

        if (present("xingjun san", me))
                return "�٣��ⶫ����������Ǯ����Ҫ��ô����";

        command("say �置�һ��������ն��쳣��������������������֮����о�ɢ��������");
        command("say ���ҩҪ����Я������ĩ�������мǣ��мǣ�");
        ob = new(__DIR__"obj/xingjunsan");
        ob->move(me, 1);
        return 1;
}
