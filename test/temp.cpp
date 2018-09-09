int main()
{
    CanMessagePack canMessagePack; // sink & source

    PacketUnpacker unpacker; // sink & pusher
    unpacker.SetOutput(canMessagePack);

    OutMessageVerifier outMessageVerifier; // sink<2> & pusher

    PushPipeSplit<2> inPacketSplit; // sink & pusher
    inPacketSplit.SetOutput<0>(unpacker);
    inPacketSplit.SetOutput<1>(outMessageVerifier);

    UDPSource udpSource; // source
    SourceReader udpReader; // pusher & puller
    udpReader.SetInput(udpSource);
    udpReader.SetOutput(inPacketSplit);



    return 0;
}