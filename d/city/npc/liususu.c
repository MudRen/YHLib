#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "liu susu", "liu", "susu" }));
        set("long", "����һ���������ŵ�����Ů�ӣ�����ת�������������⡣\n");
        set("gender", "Ů��");
        set("age", 18);
        set("per", 28);
        set("title", "������ׯ�ϰ�");
        set("nickname", HIC "����С��" NOR);
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "�����ص����л����Ļ���ʷ�ƾã���Ʒ������"
                "�Ƿ��࣬Ӧ�úúù��\n" NOR
        }));

        set("vendor_goods", ({
                __DIR__"shanzi/shan-book",
                __DIR__"shanzi/yumao-shan",
                __DIR__"shanzi/tuan-shan",
                __DIR__"shanzi/zhe-shan",
                __DIR__"shanzi/yuban-shan",
                __DIR__"shanzi/chouwu-shan",
                __DIR__"shanzi/bajiao-shan",
                __DIR__"shanzi/tanxiang-shan",
        }));

        setup();
        carry_object("/d/city/npc/cloth/gui-dress")->wear();
        set_temp("handing", carry_object("/d/city/npc/shanzi/tuan-shan"));
        add_money("silver", 2);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
