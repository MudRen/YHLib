inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ﴣ���Ÿ��ָ�����״�����ʯͷ���е����ˣ��е���
�����е����������߿�����������Ҳ�����Ƕ�������
���ģ�ǧ�˰�̬�������۾��������ˡ�������һ���߷壬ȴ��
�������������Ϊ�����塣
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "northup" :__DIR__"lianhua",
                "east" : __DIR__"shilin1", 
                "west"  :__DIR__"qingshilu",
        ]));
        setup();
        replace_program(ROOM);
}
