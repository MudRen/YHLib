inherit NPC;

void create()
{
        set_name("����", ({"pu ren", "pu"}) );
        set("gender", "����" );
        set("age", 50);
        set("long", "���Ǹ���ʵ�ͽ��������ˣ���Ȼ�·��ϴ���\n"
                    "�ܶಹ����ȴ��ʮ�ֵ����ࡣ��Ϊ���ڴ���\n"
                    "������۾�����Ѭ����һ���졣\n");
        set("attitude", "friendly");
        set("shen_type", 1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
}
