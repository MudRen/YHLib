inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书��Ķ��֣������߾����书�����ˡ��书����
С���򣬲��㷱�������ϵ�����Ҳ��ϡ�١������Ǽҿ�ջ����
ջ�ſڹ��Ű븱�������翴�졹�Ķ��������������Ѿ���˺��
�ˡ�������һ����լԺ���������ϲ���ͭ����������������
�����书��������ˡ�
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"zhongxin",
                "north" : __DIR__"kedian1",
                "south" : __DIR__"fu-damen",
        ]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
