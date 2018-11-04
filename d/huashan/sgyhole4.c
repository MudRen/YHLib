// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ���������۵�ɽ�������������ʯ����ȴ��������
�����������Ѿ�ʧ���ľ�����С�������ʯ��(wall)�Ϻܶ�С
�ˣ�ȫ�����������ƣ������������֮������ʮ�����
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "south"   : __DIR__"sgyhole3"

        ]));
        set("item_desc", ([ 
            "wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L
TEXT
        ]));

        setup();
}
void init()
{
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
        object ob;
        int c_skill;

        ob = this_player();

        c_skill = (int)ob->query_skill("sword", 1);
        if (ob->query_skill("sword", 1) < 100)
        {
                write("��Ի����������˽���Ȼ̫�ͣ��޷�����ʯ�����ݡ�\n", ob);
                return 1; 
        }

        if (! ob->can_improve_skill("sword"))
        {
                write("���ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (ob->query("jing") < 40)
        {
                write("�㾫�����ܼ��У������޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (c_skill > 150)
        {
                write("�����ʯ������̫��ǳ�ˡ�\n");
                return 1;
        }

        message_vision("$N�����ʯ��������˼�����ã��ԡ�����������"
                        "��������\n", ob);
        ob->improve_skill("sword", 1 + random(ob->query("int")));
        ob->receive_damage("jing", 35);
        ob->start_busy(2);
        return 1;
}
