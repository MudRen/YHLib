inherit NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({ "pu ren", "puren","ren" }) );
        set("gender", "����" );
        set("age", 25);
        set("int", 28);
        set("long", "���Ǹ����˴��������ˣ�������ת���Ĵ�������ͣ��\n");
        set("attitude", "peaceful");
        set("combat_exp",10000 + random(5000));
        set("chat_chance", 1);
        set("chat_msg", ({
        	CYN "����ͻȻ˵������Ժ����Ҫ���֣���������Ϊ�˷����ء�\n" NOR,
        	CYN "���۵�����˵���ں�Ժ�����кö�ô�����\n" NOR,
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
