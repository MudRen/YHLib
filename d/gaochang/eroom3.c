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
                "south" : __DIR__"eroom2",
                "northeast" : __DIR__"zoulange",
        ]));

        setup();
        replace_program(ROOM);
}
