inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�������鷿����ǽһ�Ŵ���ܣ��ڷ��źܶ���鼮������
��ʥ����������彣���ų��ԡ���ʥ������������һֱ����Ϊ
�٣���������ѧ�����ա�
LONG);
        set("exits", ([
                "west"  : __DIR__"shilu1",
        ]));
        
        setup();
        replace_program(ROOM);
}
