
inherit ROOM;

void create()
{
        set("short", "С�ӱ�");
        set("long", @LONG
�˴�λ�����ɽ��һƫƧ����Ũ���ѵأ����⸡������Χ
���������ľ���ľ��ľ�֮������Զ����С����ɽ��(dong)��
ӿ����Ȫˮ���γɣ����ȵ�ˮ���������������˳����������
ͨ��ɽ����������ɽ���ɽ���С�
LONG
        );
        set("outdoors", "quanzhen");
        set("item_desc", ([
                "dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong",
                "north" : __DIR__"shanlu16",
        ]));

        setup();
        replace_program(ROOM);
}
