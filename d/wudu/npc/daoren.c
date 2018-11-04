#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
        set_name("������", ({ "du daoren", "daoren" }));
        set("gender", "����" );
        set("age", 35);
        set("per", 20);
        set("long", "һλ���������ɱ���ݵ�������ˣ�\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("book_count", 1);

        set_skill("blade", 50);
        set_skill("ruyi-dao", 50);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("feiyan-zoubi", 50);
        set_skill("beiming-shengong",50);
        set_skill("changquan", 50);

        map_skill("unarmed", "changquan");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        set("title", "�嶾��СͷĿ");

        set("chat_chance", 2);
        set("chat_msg",({
                CYN "��������Ц������������˭�Һ������嶾�����ԣ��ܽ�"
                "�����Ĳ������ס�\n" NOR,
                CYN "�����˸�Цһ������ƶ��ר�����Ƹ��ֶ�ҩ����֤ҩ��"
                "������\n" NOR,
        }));

        setup();
        add_money("silver", 20);
        set("inquiry", ([
                "here"     : "��������������������������(lianzhi)���ֶ�ҩ��",
                "��ҩ"     : "���¿�������������(lianzhi)���ֶ�ҩ��",
                "ԭ��"     : (: ask_me :),
                "����"     : (: ask_me :),
                "����"     : "���������ô����ϧ������ֻ�ж�����ƪ��",
                "��ƪ"     : (: ask_me :),
                "������ƪ" : (: ask_me :),
                "�䷽"     : (: ask_me :),
                "��ҩ�䷽" : (: ask_me :),
        ]) );
        carry_object("/d/wudang/obj/greenrobe")->wear();
}

int ask_me()
{
        object ob, me;
        me = this_player();

        if (me->query("family/family_name") != "�嶾��")
        {
                command("say �����뱾�ɲ���ԨԴ���⻰�ǴӺζ�����");
                return 1;
        }

        if (query("book_count") < 1)
        {
                command("say �������ˣ��������Ѿ��������ˡ�");
                return 1;
        }
        add("book_count", -1);
        ob = new("/d/wudu/obj/dujing1");
        ob->move(this_object());

        command("say �˶����ϼ����˸�����ҩ�����Ʒ�����ǧ�򲻿���ʧ�ˡ�");
        command("give du jing1 to " + me->query("id"));
        return 1;
}
