inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
ÿһ�䷿�д󶼹��з���żȻ�ڱ��ϼ����������ģ�д
���Ǹ߲�����������̩���������ʮ����ȵ���������һ����
���й��Ķ��Ǻ�����������д�Ŵ����ʥ��ʦ����λ������
������ʮ�ˣ�д���ջء���·���ӹ������ġ����ŵ����֡�
LONG);
        set("exits", ([
                "south" : __DIR__"eroom1",
                "north" : __DIR__"eroom3",
        ]));
        setup();
        replace_program(ROOM);
}
