inherit ROOM;

void create()
{
        set("short", "��翷�ɽ��");
        set("long", @LONG
��������翷�ɽ�ţ�̧ͷ��������翷��������죬�嶥��
�����ƣ������ɾ����������Լ�ɼ���¥����Ǿ����
����������ɥ�������չ�����˵����ס��һЩ���ո�ǿ��Ů����
����ֻ��Ů����Ϊͽ��
LONG);
        set("outdoors", "lingjiu");
        set("exits", ([
                "westup" : __DIR__"ya",
                "southdown" : "/d/xingxiu/tianroad2"
        ]));
        set("objects", ([
                __DIR__"npc/jiuyi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
