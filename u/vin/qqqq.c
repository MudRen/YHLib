#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIB "����ħ�" NOR);
        set("long", HIB @LONG

                  ��         ħ         ��

    ������Ĵ������ţ����˽�����һ���տ��Ĵ���ӳ�����������
ԭ��������Ǵ�˵�е�����ħ��������ĵذ��̨�׾�ȫΪ��ͭ
����������������ģ�����ķ�Ѵ��������ͭ��̨�ϵĻ���ε�ʱ
��ʱ�����㲻�����˸�����������Ŵ�����һ���������ߵĸ�̨����
���š� ����̨ ���������֣���̨���ķ�ħ��ӵ����һλ��ʮ������
�����ꡣ
LONG NOR );
        set("exits", ([
                "down" : "/d/city/guangchang",
                "up" : "/d/beijing/tiananmen",
                "tulong" : "/d/tulong/tulong/haibian",
]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("item_desc", ([
                "tai" : HIB "һ���������ߵĸ�̨��������š� ����̨ ���������֡���̨���滹����һЩϣ��ŹֵĻ��ơ�\n" NOR,
]));
        setup();
}
//
void init()
{
//        add_action("do_sisuo", "yaoskill");
//        add_action("do_ganwu", "yaoexp");
//        add_action("do_get", "yaomoney");
//        add_action("do_get2", "yaodan");
}
int do_sisuo(string arg)
{
        object ob;
        ob = this_player();

        message_vision("$N���������̨��˼���ã����ֶԸ�������������������ӡ�\n",ob);
        ob->improve_skill("literate", 500000);
        ob->improve_skill("force", 500000);
        ob->improve_skill("parry", 500000);
        ob->improve_skill("dodge", 500000);
        ob->improve_skill("unarmed", 500000);
        ob->improve_skill("sword", 500000);
        ob->improve_skill("blade", 500000);
        ob->improve_skill("staff", 500000);
        ob->improve_skill("finger", 500000);
        ob->improve_skill("claw", 500000);
        ob->improve_skill("strike", 500000);
        ob->improve_skill("hammer", 500000);
        ob->improve_skill("club", 500000);
        ob->improve_skill("whip", 500000);
        ob->improve_skill("dagger", 500000);
        ob->improve_skill("throwing", 500000);
        ob->improve_skill("medical", 500000);
        ob->improve_skill("hand", 500000);
        ob->improve_skill("poison", 500000);
        ob->improve_skill("lamaism", 500000);
        ob->improve_skill("taoism", 500000);
        ob->improve_skill("buddhism", 500000);
        ob->improve_skill("chuixiao-jifa", 500000);
        ob->improve_skill("tanqin-jifa", 500000);
        ob->improve_skill("drawing", 500000);
        ob->improve_skill("idle-force", 500000);
        ob->improve_skill("cooking", 500000);
        ob->improve_skill("guzheng-jifa", 500000);
        return 1;
}
int do_ganwu(string arg)
{
        object ob;
        ob = this_player();

        if (ob->is_busy() )
        {
                return notify_fail("����������ڤ���С�\n");
                return 1; 
        }

        message_vision("$N��ϥ������������룬��ʼ����ڤ�롣\n",ob);
        ob->set("combat_exp", 20000000);
        ob->set("potential", 100000);
        ob->set("max_neili", 100000);
        ob->set("max_jingli", 100000);
        ob->set("neili", 100000);
        ob->set("jingli", 100000);
        ob->set("title", HIY "����ħ��" NOR);
        return 1;
}
int do_get()
{
        object ob, me = this_player();
        {
                message_vision(HIW 
"$N����һ�������ʱ�����ɢ�����������Ʊ�������������С�\n" NOR, this_player());
                ob = new("/clone/money/cash");
                ob -> move(me);
                ob = new("/clone/money/cash");
                ob -> move(me);
                ob = new("/clone/money/cash");
                ob -> move(me);
                ob = new("/clone/money/cash");
                ob -> move(me);
                ob = new("/clone/money/cash");
                ob -> move(me);
                return 1;
        }
}
int do_get2()
{
        object ob, me = this_player();
        {
                message_vision(HIW 
"$N����һ�������ʱ���������¼�������������ɵ��������С�\n" NOR, this_player());
                ob = new("/clone/gift/jiuzhuan");
                ob -> move(me);
                ob = new("/clone/gift/shenliwan");
                ob -> move(me);
                ob = new("/clone/gift/unknowdan");
                ob -> move(me);
                ob = new("/clone/gift/xiandan");
                ob -> move(me);
                ob = new("/clone/gift/xisuidan");
                ob -> move(me);
                return 1;
        }
}
//


