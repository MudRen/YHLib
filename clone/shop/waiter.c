#include <ansi.h>
inherit WAITER;

void create()
{
        set_name("���̻��", ({ "huo ji", "huo", "ji" }));
        set("long", "��������ҵ��̵Ļ�ơ�\n");
        set("gender", "����");
        set("age", random(10) + 20);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
